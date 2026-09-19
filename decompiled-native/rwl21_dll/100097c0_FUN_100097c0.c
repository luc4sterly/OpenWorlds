// 100097c0 FUN_100097c0 [Global]
// programa: RWL21.DLL

bool FUN_100097c0(void)

{
  undefined *puVar1;
  
  if (DAT_1005805c != 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005805c);
  }
  DAT_1005805c = 0;
  DAT_10058060 = 0;
  DAT_10058054 = FUN_100371c0(s_clumplist_10058064,0x19c);
  puVar1 = PTR_DAT_1005b69c;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2f0) = 0;
  *(undefined4 *)(puVar1 + 0x2f4) = 0;
  *(undefined4 *)(puVar1 + 0x2f8) = 0;
  *(undefined4 *)(puVar1 + 0x2fc) = 0;
  *(undefined4 *)(puVar1 + 0x300) = 0;
  *(undefined4 *)(puVar1 + 0x304) = 0;
  *(undefined4 *)(puVar1 + 800) = 0;
  *(undefined4 *)(puVar1 + 0x324) = 0;
  *(undefined4 *)(puVar1 + 0x328) = 0;
  *(undefined4 *)(puVar1 + 0x32c) = 0;
  puVar1[0x332] = 3;
  *(undefined4 *)(puVar1 + 0x348) = 0;
  return (bool)('\x01' - (DAT_10058054 == (undefined4 *)0x0));
}


