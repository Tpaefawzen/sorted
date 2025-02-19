#include "precomp.h"
#include "SortedSyntax.h"
#include "EnglishNumbers.h"
#include "GermanNumbers.h"
#include <ctype.h>
#include "OPP.h"
#include "SortedInterpreter.h"

long SortedInterpreter::GetDataValue( SLID* ps )
{
    long Result = 0;
    SLIDE_INFO* psi;
    SLIDE* psA;
    
    switch( ps->Type & 0xFF )
    {
    case SLID_TYPE_NUMBER:
        Result = m_pCI->Data[ps->Index];
        break;
    case SLID_TYPE_SUM:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        Result = GetDataValue(&psA->_[0])+GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_DIFF:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        Result = GetDataValue(&psA->_[0])-GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_PROD:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        Result = GetDataValue(&psA->_[0])*GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_RATIO:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        Result = GetDataValue(&psA->_[0])/GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_NAND:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        Result = ~GetDataValue(&psA->_[0]) & ~GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_CONDITION:
        psi = &(m_pCI->Type[ps->Type-1]);
        psA = &(m_pCI->Code[psi->Index + ps->Index]);
        if( psA->Flags == SLIDE_COMPARE_EQUAL )
            Result = GetDataValue(&psA->_[0]) == GetDataValue(&psA->_[1]);
        else
            Result = GetDataValue(&psA->_[0]) < GetDataValue(&psA->_[1]);
        break;
    case SLID_TYPE_LABEL:
        Result = m_pKnownLabel[ps->Index];
        break;
    }
    if( ps->Type & SLID_TYPE_INDIRECT )
        Result = m_pCI->Data[Result-1];

    return Result;
}

long* SortedInterpreter::GetDataPointer( SLID* ps )
{
    long* lpResult = 0;
    switch( ps->Type & 0xFF )
    {
    case SLID_TYPE_NUMBER:
        lpResult = &(m_pCI->Data[ps->Index]);
        break;
    }
    if( lpResult && (ps->Type & SLID_TYPE_INDIRECT) )
        lpResult = &(m_pCI->Data[*lpResult]);

    return lpResult;
}

void SortedInterpreter::Interpret( CODEINFO* pCI )
{
    int i,j;

    m_pCI = pCI;
    m_pKnownLabel = new int[pCI->nLabelsCount+2];

    SLIDE_INFO* psi = &(pCI->Type[SLIDE_INFO_STATEMENTS]), *psiA;
    SLIDE* ps = &(pCI->Code[psi->Index]), *psA;

    for( i = 0; i < pCI->nLabelsCount; m_pKnownLabel[i++] = 0 ) {}

    for( j = 0; j < psi->Count; j++, ps++ )
        if( ps->_[0].Type == SLID_TYPE_LABEL )
            m_pKnownLabel[ps->_[0].Index] = j;
    
    psi = &(pCI->Type[SLIDE_INFO_STATEMENTS]);
    for( m_iPC = 0; m_iPC < psi->Count; m_iPC++ )
    {
        ps = &(pCI->Code[psi->Index+m_iPC]);
        psiA = &(m_pCI->Type[ps->_[0].Type-1]);
        psA = &(pCI->Code[psiA->Index + ps->_[0].Index]);
        switch( ps->_[0].Type )
        {
        case SLID_TYPE_ASSIGN:
            *GetDataPointer(&psA->_[1]) = GetDataValue(&psA->_[0]);
            break;
        case SLID_TYPE_READ:
            *GetDataPointer(&psA->_[1]) = getchar();
            break;
        case SLID_TYPE_WRITE:
            switch(psA->Flags)
            {
            case SLIDE_FORMAT_ENGLISH_CARDINAL:
                printf( "%s\n", IntegerToEnglishCardinal( (int) GetDataValue(&psA->_[0]) ));
                break;

            case SLIDE_FORMAT_ENGLISH_ORDINAL:
                printf( "%s\n", IntegerToEnglishOrdinal( (int) GetDataValue(&psA->_[0]) ));
                break;

            case SLIDE_FORMAT_GERMAN_CARDINAL:
                printf( "%s\n", IntegerToGermanCardinal( (int) GetDataValue(&psA->_[0]) ));
                break;

            case SLIDE_FORMAT_GERMAN_ORDINAL:
                printf( "%s\n", IntegerToGermanOrdinal( (int) GetDataValue(&psA->_[0]) ));
                break;

            default:
                putchar( (int) GetDataValue(&psA->_[0]) );
            }
            
            break;
        case SLID_TYPE_JUMP:
            psiA = &(m_pCI->Type[SLIDE_INFO_JUMPS]);
            psA = &(pCI->Code[psiA->Index + ps->_[0].Index]);
            if( psA->Flags == SLIDE_UNCONDITIONAL_JUMP )
                m_iPC = GetDataValue(&psA->_[0]);
            else if( GetDataValue(&psA->_[1]) )
                m_iPC = GetDataValue(&psA->_[0]);
            break;
        }
    }
    delete [] m_pKnownLabel;
}
