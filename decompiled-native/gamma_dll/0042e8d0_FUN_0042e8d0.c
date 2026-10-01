// 0042e8d0 FUN_0042e8d0 [Global]
// program: gamma.dll

void * __cdecl FUN_0042e8d0(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 < param_2; param_1 = param_1 + 0x13) {
    FUN_0042e970(param_3,param_1);
    FUN_0042e930((void *)((int)param_3 + 0x10),param_1 + 4);
    FUN_0042e930((void *)((int)param_3 + 0x1c),param_1 + 7);
    FUN_0042e930((void *)((int)param_3 + 0x28),param_1 + 10);
    FUN_0042e930((void *)((int)param_3 + 0x34),param_1 + 0xd);
    param_3 = (void *)((int)param_3 + 0x4c);
  }
  return param_3;
}


