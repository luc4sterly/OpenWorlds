// 100166b0 FUN_100166b0 [Global]
// programa: RWL21.DLL

undefined4 FUN_100166b0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_1005dfc8;
  do {
    if (piVar2 == (int *)0x0) break;
    piVar1 = (int *)piVar2[0x18];
    iVar3 = FUN_1000f2b0(piVar2);
    FUN_10037010(DAT_1005a0d4,piVar2);
    piVar2 = piVar1;
  } while (iVar3 != 0);
  DAT_1005dfcc = 0;
  DAT_1005dfc8 = (int *)0x0;
  FUN_100370f0();
  FUN_100370f0();
  FUN_100370f0();
  FUN_1001d4c0(DAT_1005dfd0);
  return 1;
}


