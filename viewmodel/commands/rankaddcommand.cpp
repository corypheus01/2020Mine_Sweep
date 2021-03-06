#include "rankaddcommand.h"
#include "../msviewmodel.h"
//ccx 7.12
RankAddCommand::RankAddCommand(MSViewModel* p) throw(): m_pVM(p), m_param("0",0)
{
}

void RankAddCommand::SetParameter(const std::any& param)
{
    m_param = std::any_cast<UserParameter>(param);
    //qDebug()<<"setpara";
}

void RankAddCommand::Exec()
{
    bool b_result = m_pVM->rankadd(m_param);
    m_pVM->Fire_OnCommandComplete("leftblockclk", b_result);
}
