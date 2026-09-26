// 00403b83 FUN_00403b83 [Global]
// programa: run.exe

uint * __cdecl FUN_00403b83(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  
  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_004019f0(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}


