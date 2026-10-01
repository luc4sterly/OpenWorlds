// 10004120 RwRemoveChildFromClump [Global]
// program: RWL21.DLL

int RwRemoveChildFromClump(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x4120  333  RwRemoveChildFromClump */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x174);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x178);
      if (param_1 == iVar2) {
        if (*(int *)(iVar1 + 0x17c) == iVar2) {
          *(undefined4 *)(iVar1 + 0x178) = 0;
          *(undefined4 *)(iVar1 + 0x17c) = 0;
        }
        else {
          iVar3 = *(int *)(iVar2 + 0x184);
          *(int *)(iVar1 + 0x178) = iVar3;
          *(undefined4 *)(iVar3 + 0x180) = 0;
        }
        *(undefined4 *)(iVar2 + 0x180) = 0;
        *(undefined4 *)(iVar2 + 0x184) = 0;
      }
      else {
        iVar3 = *(int *)(iVar1 + 0x17c);
        if (param_1 == iVar3) {
          if (iVar3 == iVar2) {
            *(undefined4 *)(iVar1 + 0x178) = 0;
            *(undefined4 *)(iVar1 + 0x17c) = 0;
          }
          else {
            iVar2 = *(int *)(iVar3 + 0x180);
            *(int *)(iVar1 + 0x17c) = iVar2;
            *(undefined4 *)(iVar2 + 0x184) = 0;
          }
          *(undefined4 *)(iVar3 + 0x180) = 0;
          *(undefined4 *)(iVar3 + 0x184) = 0;
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x184) = *(undefined4 *)(param_1 + 0x184);
          *(undefined4 *)(*(int *)(param_1 + 0x184) + 0x180) = *(undefined4 *)(param_1 + 0x180);
          *(undefined4 *)(param_1 + 0x180) = 0;
          *(undefined4 *)(param_1 + 0x184) = 0;
        }
      }
      *(undefined4 *)(param_1 + 0x174) = 0;
      *(undefined1 *)(param_1 + 0x12d) = 1;
      return param_1;
    }
  }
  return param_1;
}


