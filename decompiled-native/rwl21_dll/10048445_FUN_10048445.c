// 10048445 FUN_10048445 [Global]
// program: RWL21.DLL

float10 __fastcall FUN_10048445(undefined4 param_1)

{
  float10 fVar1;
  
  if ((char)param_1 != '\0') {
    fVar1 = (float10)3.141592653589793;
    if ((char)((uint)param_1 >> 8) != '\0') {
      fVar1 = -fVar1;
    }
    return fVar1;
  }
  return (float10)0;
}


