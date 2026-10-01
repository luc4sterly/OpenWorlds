// 00450c20 FUN_00450c20 [Global]
// program: gamma.dll

void __cdecl FUN_00450c20(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = DAT_0049e528; (iVar2 != 0 && (iVar2 != param_1)); iVar2 = *(int *)(iVar2 + 8)) {
    iVar1 = iVar2;
  }
  if (iVar2 == 0) {
    FUN_00458ca0();
  }
  if (iVar1 == 0) {
    DAT_0049e528 = *(int *)(iVar2 + 8);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
  }
  return;
}


