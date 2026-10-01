// 00450be0 FUN_00450be0 [Global]
// program: gamma.dll

void __cdecl FUN_00450be0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = DAT_0049e528;
      (puVar2 != (undefined4 *)0x0 && (*(uint *)*param_1 < *(uint *)*puVar2));
      puVar2 = (undefined4 *)puVar2[2]) {
    puVar1 = puVar2;
  }
  param_1[2] = puVar2;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_0049e528 = param_1;
  }
  else {
    puVar1[2] = param_1;
  }
  return;
}


