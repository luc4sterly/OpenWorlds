// 10041d80 FUN_10041d80 [Global]
// programa: RWL21.DLL

void FUN_10041d80(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    iVar2 = 8;
    if (8 < param_1[2]) {
      piVar1 = param_1 + 0x107;
      do {
        if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
          if (*(short *)((int)piVar1 + -2) == 6) {
            FUN_10037010(DAT_1005b8d0,(undefined4 *)*piVar1);
          }
          else {
            (**(code **)(PTR_DAT_1005b69c + 0x358))();
          }
        }
        piVar1 = piVar1 + 0x1d;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[2]);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
  }
  return;
}


