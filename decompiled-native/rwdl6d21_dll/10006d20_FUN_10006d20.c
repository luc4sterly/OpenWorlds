// 10006d20 FUN_10006d20 [Global]
// program: RWDL6D21.DLL

void FUN_10006d20(byte *param_1,undefined1 *param_2)

{
  *param_2 = (&DAT_1007c0d0)[*param_1];
  param_2[1] = (&DAT_1007c0d0)[param_1[1]];
  param_2[2] = (&DAT_1007c0d0)[param_1[2]];
  return;
}


