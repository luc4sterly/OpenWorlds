// 10006ba0 FUN_10006ba0 [Global]
// program: RWDLDD21.DLL

undefined4 * FUN_10006ba0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_10024a80(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    param_1[1] = 0x10;
    param_1[5] = 0;
    *param_1 = 2;
    param_1[2] = 0xf800;
    param_1[3] = 0x7e0;
    param_1[4] = 0x1f;
    return param_1;
  }
  return (undefined4 *)0x0;
}


