// 100483e2 FUN_100483e2 [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x10048401) */

float10 __fastcall FUN_100483e2(char param_1)

{
  float10 in_ST0;
  float10 fVar1;
  
  fVar1 = (float10)fpatan(ABS(in_ST0),(float10)1);
  if (param_1 != '\0') {
    fVar1 = -fVar1;
  }
  return fVar1;
}


