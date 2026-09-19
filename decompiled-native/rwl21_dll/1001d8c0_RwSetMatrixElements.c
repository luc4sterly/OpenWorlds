// 1001d8c0 RwSetMatrixElements [Global]
// programa: RWL21.DLL

undefined4 * RwSetMatrixElements(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
                    /* 0x1d8c0  428  RwSetMatrixElements */
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    param_1 = (undefined4 *)0x0;
  }
  if (param_1 != (undefined4 *)0x0) {
    iVar4 = 4;
    puVar2 = param_1;
    do {
      iVar3 = 4;
      puVar5 = puVar2;
      puVar6 = param_2;
      do {
        uVar1 = *puVar6;
        puVar6 = puVar6 + 4;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined1 *)((int)param_1 + 0x41) = 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


