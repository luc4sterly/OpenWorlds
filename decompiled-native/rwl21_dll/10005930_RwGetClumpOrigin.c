// 10005930 RwGetClumpOrigin [Global]
// programa: RWL21.DLL

undefined4 * __thiscall RwGetClumpOrigin(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x5930  162  RwGetClumpOrigin */
  iVar2 = 0;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    if (param_1 != 0) {
      this = (void *)0x0;
      iVar1 = param_1;
      do {
        if ((*(char *)(iVar1 + 0x12d) != '\0') || (*(char *)(iVar1 + 0x171) != '\0')) {
          iVar2 = iVar1;
        }
        iVar1 = *(int *)(iVar1 + 0x174);
      } while (iVar1 != 0);
    }
    if (iVar2 != 0) {
      FUN_10004700(this,iVar2,(float *)iVar2);
    }
    *param_2 = *(undefined4 *)(param_1 + 0x30);
    param_2[1] = *(undefined4 *)(param_1 + 0x34);
    param_2[2] = *(undefined4 *)(param_1 + 0x38);
    return param_2;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


