// 00432324 FUN_00432324 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00432324(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int *piVar4;
  char *pcVar5;
  
  if ((DAT_0043eae4 != (int *)0x0) && (in_EAX != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar5 = in_EAX;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    for (piVar4 = DAT_0043eae4; *piVar4 != 0; piVar4 = piVar4 + 1) {
      iVar2 = FUN_00432eea(*piVar4,in_EAX);
      if ((iVar2 == 0) && (*(char *)(extraout_ECX + (~uVar3 - 1)) == '=')) {
        iVar2 = ~uVar3 + extraout_ECX;
        goto LAB_0043237e;
      }
    }
  }
  iVar2 = 0;
LAB_0043237e:
  return CONCAT44(param_2,iVar2);
}


