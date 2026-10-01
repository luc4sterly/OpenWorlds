// 0043ffc0 FUN_0043ffc0 [Global]
// program: gamma.dll

void __thiscall FUN_0043ffc0(void *param_1,LPCSTR param_2)

{
  int iVar1;
  
  if (param_2 != (LPCSTR)0x0) {
    iVar1 = FUN_0043fe30(param_1,param_2);
    if (iVar1 != 0) {
      *(undefined4 *)((int)param_1 + 8) = 1;
    }
  }
  return;
}


