PAL evil Proc re-design
Mailbox receipt
void Determine Who Assigned  {
  If Who not in addressee list
          Fwrd to Who
}

void BaselineAction ( SubmittalType ) {
    switch ( SubmittalType ) {
        S1:
            EstProjectBudget = PlugBudgetAmount;
        S2:
            if ( ! BudgetAmount ) {
                if ( ! PlugBudgetAmount ) {
                    NotifyITPOD( provide budget amount asap );
                    ScheduleITPOD-FollowUp;
                    RecordProjectSubmittalDefectNote;
                }
            }
            if ( OwnerArchitect ) {
                ConfirmOwnerArchitectId;
                ReachOutToOwnerArchitect ( isAwareProject, isPartOrgPortfolio );
                if ( isPartOrgPortfolio ) {
                    RecordSame;
                    ownerWantOEA-Assist;
                    Record( ownerWantOEA-Assist || noIntentReview );
                } else {

                }
            } else {
                IdentifyOwnerArchitect;
                ReachOutToOwnerArchitect;
            }
    S3:
    S4:
    SPR:
    BCP:
    S1-Consult:
    S2-Consult:
    S3-Consult:
    S4-Consult:
  }

/* ****************************************************************
 *  Attempt to plug an estimated project budget amount in for the
 *  project.
 *  It's ONLY an estimate; to help decision making based on history
 *
 * Return: integer value derived from similar recorded works.
 *         0 - zero if no like work found.
 * ****************************************************************/
 
int PlugBudgetAmount( SubmittalType, TypeWork, Agency, ... ) {
    EstBudget = FindNumLikeProjects( TypeWork, Agency, BudgetAmount, LatestPossibleLife );
    if (EstBudget)
        return EstBudget;
    else
        return 0;
}

void NotifyMgmt( weekly ) {
    NumProjSubmittalsRecvd;
    TypeProjSubmittalsRevc;
    SubmittalsPartOfOwnerPortfolio; // as % of num NumProjSubmittalsRecvd
                                    // NO NEED FOR REVIEW UON/Requested
    NumProjSubmittalsWithArch;
}
