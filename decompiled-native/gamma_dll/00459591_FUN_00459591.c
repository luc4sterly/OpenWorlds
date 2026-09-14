// 00459591 FUN_00459591 [Global]
// programa: gamma.dll

float10 __cdecl FUN_00459591(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  if ((char)uVar1 == '\0') {
    uVar1 = 0;
  }
  return (float10)(double)CONCAT44(0x7ff80000,uVar1);
}


