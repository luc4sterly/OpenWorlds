// 1002a7d0 FUN_1002a7d0 [Global]
// programa: RWL21.DLL

undefined1 * FUN_1002a7d0(undefined1 *param_1,uint param_2)

{
  DAT_1005ad24 = &DAT_1005ad68;
  if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
    DAT_1005ad24 = &DAT_1005ad28;
  }
  *DAT_1005ad24 = param_1;
  switch(param_2 & 0x30) {
  case 0:
    return (undefined1 *)DAT_1005ad24[param_2 & 0xf];
  case 0x10:
    return &LAB_1002a890;
  case 0x20:
    return &LAB_1002ad70;
  case 0x30:
    param_1 = &LAB_1002b260;
  }
  return param_1;
}


