// 1002f7f0 RwGetSceneNumLights [Global]
// program: RWL21.DLL

int RwGetSceneNumLights(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2f7f0  243  RwGetSceneNumLights */
  if (param_1 == 0) {
    iVar2 = -1;
  }
  else {
    iVar3 = 0;
    for (puVar1 = *(undefined4 **)(param_1 + 0x10); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = 0;
    for (puVar1 = *(undefined4 **)(param_1 + 0x14); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = iVar2 + iVar3;
  }
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  return iVar2;
}


