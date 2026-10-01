// 10006c70 FUN_10006c70 [Global]
// program: RWDL8D21.DLL

void FUN_10006c70(byte *param_1,undefined1 *param_2)

{
  *param_2 = (&DAT_100780d0)[*param_1];
  param_2[1] = (&DAT_100780d0)[param_1[1]];
  param_2[2] = (&DAT_100780d0)[param_1[2]];
  return;
}


