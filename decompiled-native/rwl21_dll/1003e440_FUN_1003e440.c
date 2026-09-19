// 1003e440 FUN_1003e440 [Global]
// programa: RWL21.DLL

undefined4 FUN_1003e440(int param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_2[2];
  piVar2 = (int *)(*param_2 + uVar1 * 4);
  uVar4 = uVar1;
  do {
    piVar2 = piVar2 + -1;
    if (uVar4 == 0) {
      uVar4 = param_2[1];
      if (uVar4 <= uVar1) {
        iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*param_2,uVar4 * 4 + 0xa0);
        if (iVar3 == 0) {
          return 0;
        }
        *param_2 = iVar3;
        param_2[1] = uVar4 + 0x28;
      }
      *(int *)(*param_2 + param_2[2] * 4) = param_1;
      param_2[2] = param_2[2] + 1;
      return 0;
    }
    uVar4 = uVar4 - 1;
  } while (*piVar2 != param_1);
  return 0;
}


