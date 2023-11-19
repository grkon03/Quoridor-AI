#include "shorthand.hpp"

#include <algorithm>

namespace QuoridorAI::Util
{
    namespace
    {
        int _MIMSNK(char file, char rank)
        {
            int _file = file - 'a';
            int _rank = rank - '0';

            if (FileA > _file || _file >= FileJ)
                return -1;
            else if (Rank0 > _rank || _rank >= Rank9)
                return -1;
            else
                return _rank * 9 + _file;
        }

        int _MIMSNV(char file, char rank)
        {
            int _file = file - 'a';
            int _rank = rank - '0';

            if (FileA >= _file || _file >= FileJ)
                return -1;
            else if (Rank0 > _rank || _rank >= FileI)
                return -1;
            else
                return _rank * 8 + _file - 1;
        }

        int _MIMSNH(char file, char rank)
        {
            int _file = file - 'a';
            int _rank = rank - '0';

            if (FileA > _file || _file >= FileI)
                return -1;
            else if (Rank0 >= _rank || _rank >= Rank9)
                return -1;
            else
                return (_rank - 1) * 8 + _file + 64;
        }
    }

    int MakeIMoveSN(std::string sn)
    {
        if (sn.size() < 3)
            return -1;

        switch (sn[0])
        {
        case 'K':
            return _MIMSNK(sn[1], sn[2]);
        case 'V':
            return _MIMSNV(sn[1], sn[2]);
        case 'H':
            return _MIMSNH(sn[1], sn[2]);
        default:
            return -1;
        }
    }

    std::vector<int> MakeIMoveSNs(std::vector<std::string> sns)
    {
        std::vector<int> ret;
        std::transform(sns.begin(), sns.end(), ret.begin(), MakeIMoveSN);
        return ret;
    }
}