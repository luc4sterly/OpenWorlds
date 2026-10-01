// 10004500 RwAddChildToClump [Global]
// program: RWL21.DLL

int RwAddChildToClump(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
                    /* 0x4500  2  RwAddChildToClump */
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x174);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      FUN_1000cba0(1);
    }
    else if (iVar1 != 0) {
      uVar4 = *(uint *)(iVar1 + 0x178);
      if (param_2 == uVar4) {
        if (*(uint *)(iVar1 + 0x17c) == uVar4) {
          *(undefined4 *)(iVar1 + 0x178) = 0;
          *(undefined4 *)(iVar1 + 0x17c) = 0;
        }
        else {
          iVar2 = *(int *)(uVar4 + 0x184);
          *(int *)(iVar1 + 0x178) = iVar2;
          *(undefined4 *)(iVar2 + 0x180) = 0;
        }
        *(undefined4 *)(uVar4 + 0x180) = 0;
        *(undefined4 *)(uVar4 + 0x184) = 0;
      }
      else {
        uVar3 = *(uint *)(iVar1 + 0x17c);
        if (param_2 == uVar3) {
          if (uVar3 == uVar4) {
            *(undefined4 *)(iVar1 + 0x178) = 0;
            *(undefined4 *)(iVar1 + 0x17c) = 0;
          }
          else {
            iVar2 = *(int *)(uVar3 + 0x180);
            *(int *)(iVar1 + 0x17c) = iVar2;
            *(undefined4 *)(iVar2 + 0x184) = 0;
          }
          *(undefined4 *)(uVar3 + 0x180) = 0;
          *(undefined4 *)(uVar3 + 0x184) = 0;
        }
        else {
          *(undefined4 *)(*(int *)(param_2 + 0x180) + 0x184) = *(undefined4 *)(param_2 + 0x184);
          *(undefined4 *)(*(int *)(param_2 + 0x184) + 0x180) = *(undefined4 *)(param_2 + 0x180);
          *(undefined4 *)(param_2 + 0x180) = 0;
          *(undefined4 *)(param_2 + 0x184) = 0;
        }
      }
      *(undefined4 *)(param_2 + 0x174) = 0;
      *(undefined1 *)(param_2 + 0x12d) = 1;
    }
  }
  if (*(int *)(param_1 + 0x17c) == 0) {
    *(uint *)(param_1 + 0x178) = param_2;
    *(uint *)(param_1 + 0x17c) = param_2;
    *(undefined4 *)(param_2 + 0x180) = 0;
    *(undefined4 *)(param_2 + 0x184) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x184) = 0;
    *(undefined4 *)(param_2 + 0x180) = *(undefined4 *)(param_1 + 0x17c);
    *(uint *)(*(int *)(param_1 + 0x17c) + 0x184) = param_2;
    *(uint *)(param_1 + 0x17c) = param_2;
  }
  *(int *)(param_2 + 0x174) = param_1;
  uVar4 = param_2;
  uVar3 = RwGetClumpOwner(param_1);
  uVar4 = FUN_1002c120(uVar3,uVar4);
  if (uVar4 == 0) {
    return 0;
  }
  *(undefined1 *)(param_2 + 0x12d) = 1;
  return param_1;
}


