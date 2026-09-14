// 00454d00 FUN_00454d00 [Global]
// programa: gamma.dll

undefined4 FUN_00454d00(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = 0;
  puVar3 = (undefined4 *)&DAT_00482468;
  do {
    if (((*(ushort *)(puVar3 + 1) >> 7 & 7) != 0) && (iVar1 = FUN_00454f40(puVar3), iVar1 != 0)) {
      uVar2 = 0xffffffff;
    }
    puVar3 = (undefined4 *)puVar3[0x14];
  } while (puVar3 != (undefined4 *)0x0);
  return uVar2;
}


