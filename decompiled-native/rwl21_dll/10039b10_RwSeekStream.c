// 10039b10 RwSeekStream [Global]
// programa: RWL21.DLL

undefined4 RwSeekStream(int *param_1,int param_2)

{
  FILE *_File;
  int iVar1;
  
                    /* 0x39b10  364  RwSeekStream */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_1[1] != 1) {
    FUN_1000cba0(0x56);
    return 0;
  }
  if (param_2 == 0) {
    return 1;
  }
  iVar1 = *param_1;
  if (0 < iVar1) {
    if (iVar1 < 3) {
      _File = (FILE *)param_1[2];
      iVar1 = _fseek(_File,param_2,1);
      if (iVar1 != 0) {
        if ((_File->_flag & 0x10U) != 0) {
          FUN_1000cba0(0x58);
        }
        return 0;
      }
      return 1;
    }
    if (iVar1 == 3) {
      if ((uint)param_1[3] < (uint)(param_2 + param_1[2])) {
        param_1[2] = param_1[3];
        FUN_1000cba0(0x58);
        return 0;
      }
      param_1[2] = param_2 + param_1[2];
      return 1;
    }
  }
  FUN_1000cba0(0x57);
  return 0;
}


