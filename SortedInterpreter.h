#pragma once

#include "precomp.h"
#include "SortedSyntax.h"
#include "EnglishNumbers.h"
#include "GermanNumbers.h"
#include <ctype.h>
#include "OPP.h"

class SortedInterpreter 
    {
    public:
        void Interpret( CODEINFO* pCI );

    protected:
        long* GetDataPointer( SLID* ps );
        long GetDataValue( SLID* ps );

        int m_iPC;
        int* m_pKnownLabel;
        CODEINFO* m_pCI;
    };
