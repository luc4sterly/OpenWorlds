// 10039790 RwCloseStream [Global]
// programa: RWL21.DLL

undefined4 RwCloseStream(int *param_1,int *param_2)

{
  int iVar1;
  
                    /* 0x39790  30  RwCloseStream */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *param_1;
  if (0 < iVar1) {
    if (iVar1 < 3) {
      iVar1 = _fclose((FILE *)param_1[2]);
      if (iVar1 != 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))();
        return 0;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
      return 1;
    }
    if (iVar1 == 3) {
      if (param_1[1] == 1) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
        return 1;
      }
      if (param_2 == (int *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
        FUN_1000cba0(1);
        return 0;
      }
      *param_2 = param_1[4];
      param_2[1] = param_1[2];
      (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
      return 1;
    }
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
  FUN_1000cba0(0x57);
  return 0;
}


