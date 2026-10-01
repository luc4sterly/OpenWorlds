// 10020c20 FUN_10020c20 [Global]
// program: RWL21.DLL

int * FUN_10020c20(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piStack_8;
  
  iVar2 = param_1[1];
  if (*param_1 == iVar2) {
    iVar3 = iVar2 + ((int)(iVar2 + 1 + (iVar2 + 1 >> 0x1f & 3U)) >> 2);
    iVar1 = iVar3 * 4 + 0xc;
    if (iVar2 == 8) {
      piStack_8 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x350))(0xc,iVar1);
      if (piStack_8 != (int *)0x0) {
        piVar4 = param_1;
        piVar5 = piStack_8;
        for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
      }
      FUN_10037010(DAT_1005accc,param_1);
    }
    else {
      piStack_8 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x354))(param_1,iVar1);
    }
    param_1 = piStack_8;
    if (piStack_8 == (int *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      piStack_8[1] = iVar3;
    }
  }
  if (param_1 != (int *)0x0) {
    param_1[*param_1 + 2] = param_2;
    *param_1 = *param_1 + 1;
  }
  return param_1;
}


