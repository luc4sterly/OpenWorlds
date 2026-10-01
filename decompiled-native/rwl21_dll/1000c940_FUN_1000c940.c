// 1000c940 FUN_1000c940 [Global]
// program: RWL21.DLL

undefined4 FUN_1000c940(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(PTR_DAT_1005b69c + 0xc);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x30))(puVar2);
    }
    FUN_1000a2d0(puVar2);
    puVar2 = puVar1;
  }
  FUN_100370f0();
  return 1;
}


