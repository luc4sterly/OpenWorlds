// 1001bc30 FUN_1001bc30 [Global]
// program: RWL21.DLL

undefined4 FUN_1001bc30(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < DAT_1005dfd4) {
    iVar4 = 0;
    do {
      puVar1 = *(undefined4 **)(DAT_1005dfdc + iVar4);
      if (puVar1 == (undefined4 *)0x0) break;
      if ((uint)puVar1[0x10] < 2) {
        uVar2 = FUN_10020be0((undefined4 *)puVar1[0xf]);
        puVar1[0xf] = uVar2;
        FUN_10037010(DAT_1005ac24,puVar1);
      }
      else {
        puVar1[0x10] = puVar1[0x10] - 1;
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_1005dfd4);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005dfdc);
  FUN_100370f0();
  return 1;
}


