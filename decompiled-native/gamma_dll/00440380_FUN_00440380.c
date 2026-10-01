// 00440380 FUN_00440380 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00440380(void *param_1)

{
  CoInitialize((LPVOID)0x0);
  *(undefined4 *)((int)param_1 + 8) = 0;
  if ((*(int *)((int)param_1 + 0x3c) != 0) && (*(int *)((int)param_1 + 0x34) == 0)) {
    FUN_00440460(param_1,*(int *)((int)param_1 + 0x3c));
    *(undefined4 *)((int)param_1 + 0x34) = 1;
  }
  return 1;
}


