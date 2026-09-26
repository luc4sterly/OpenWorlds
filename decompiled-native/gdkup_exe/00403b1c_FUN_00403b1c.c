// 00403b1c FUN_00403b1c [Global]
// programa: gdkup.exe

void FUN_00403b1c(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  puVar1 = &DAT_0040b464;
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
  } while (in_EAX != puVar1[1]);
  *(byte *)(in_EAX + 0xc) = *(byte *)(puVar1[1] + 0xc) | 3;
  *puVar2 = *puVar1;
  *puVar1 = DAT_0040b460;
  DAT_0040b460 = puVar1;
  return;
}


