// 00426c60 FUN_00426c60 [Global]
// programa: gamma.dll

void __fastcall FUN_00426c60(int *param_1)

{
  if (*param_1 + param_1[1] != DAT_0049d280) {
    FUN_00402800(s_memscrat_00471cc0,0x3d);
  }
  DAT_0049d284 = DAT_0049d284 + param_1[1];
  DAT_0049d280 = *param_1;
  return;
}


