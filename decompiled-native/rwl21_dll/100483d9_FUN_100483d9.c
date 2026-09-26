// 100483d9 FUN_100483d9 [Global]
// programa: RWL21.DLL

float10 FUN_100483d9(void)

{
  char extraout_CL;
  char extraout_CH;
  undefined1 auVar1 [10];
  unkbyte10 extraout_ST1;
  float10 fVar2;
  
  auVar1 = FUN_1004840c();
  fVar2 = (float10)fpatan(auVar1,extraout_ST1);
  if (extraout_CL != '\0') {
    fVar2 = (float10)3.141592653589793 - fVar2;
  }
  if (extraout_CH != '\0') {
    fVar2 = -fVar2;
  }
  return fVar2;
}


