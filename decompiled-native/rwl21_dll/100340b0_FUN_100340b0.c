// 100340b0 FUN_100340b0 [Global]
// programa: RWL21.DLL

int FUN_100340b0(int param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = _fprintf(param_2,s_ModelBegin_1005af20);
  if (iVar1 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  iVar1 = FUN_10034130(param_2,DAT_1005af10,param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = _fprintf(param_2,s_ModelEnd_1005af14);
  if (iVar1 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  return param_1;
}


