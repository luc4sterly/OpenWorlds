// 0042db6b FUN_0042db6b [Global]
// programa: sfmain.exe

float10 FUN_0042db6b(void)

{
  code *pcVar1;
  float10 fVar2;
  
  pcVar1 = (code *)swi(6);
  fVar2 = (float10)(*pcVar1)();
  return fVar2 / fVar2;
}


