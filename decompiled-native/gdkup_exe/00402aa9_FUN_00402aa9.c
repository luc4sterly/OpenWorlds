// 00402aa9 FUN_00402aa9 [Global]
// program: gdkup.exe

undefined * __fastcall FUN_00402aa9(int param_1,undefined4 *param_2)

{
  char cVar1;
  char *in_EAX;
  char extraout_CH;
  uint uVar2;
  uint extraout_ECX;
  undefined3 uVar3;
  char *pcVar4;
  char *pcVar5;
  int unaff_EBX;
  undefined *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  
  pcVar4 = in_EAX;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = in_EAX;
  }
  while (((&DAT_00408958)[(byte)(*pcVar4 + 1)] & 2) != 0) {
    pcVar4 = pcVar4 + 1;
  }
  cVar1 = *pcVar4;
  uVar2 = CONCAT22((short)((uint)param_1 >> 0x10),CONCAT11(cVar1,(char)param_1));
  if ((cVar1 == '+') || (cVar1 == '-')) {
    pcVar4 = pcVar4 + 1;
  }
  if (unaff_EBX == 0) {
    if ((*pcVar4 == '0') && ((pcVar4[1] == 'x' || (pcVar4[1] == 'X')))) {
      unaff_EBX = 0x10;
    }
    else if (*pcVar4 == '0') {
      unaff_EBX = 8;
    }
    else {
      unaff_EBX = 10;
    }
  }
  if ((unaff_EBX < 2) || (0x24 < unaff_EBX)) {
    FUN_00403848(uVar2,pcVar4);
    puVar6 = (undefined *)0x0;
  }
  else {
    if (((unaff_EBX == 0x10) && (*pcVar4 == '0')) && ((pcVar4[1] == 'x' || (pcVar4[1] == 'X')))) {
      pcVar4 = pcVar4 + 2;
    }
    uVar2 = uVar2 & 0xffffff00;
    pcVar5 = pcVar4;
    puVar6 = (undefined *)0x0;
    while( true ) {
      uVar8 = FUN_00402c1e(uVar2,pcVar5);
      pcVar5 = (char *)((ulonglong)uVar8 >> 0x20);
      uVar3 = (undefined3)(extraout_ECX >> 8);
      if (unaff_EBX <= (int)uVar8) break;
      uVar2 = extraout_ECX;
      if ((&PTR_FUN_00408a6c)[unaff_EBX] < puVar6) {
        uVar2 = CONCAT31(uVar3,1);
      }
      puVar7 = (undefined *)((int)puVar6 * unaff_EBX + (int)uVar8);
      if (puVar7 < puVar6) {
        uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
      }
      pcVar5 = pcVar5 + 1;
      puVar6 = puVar7;
    }
    if (pcVar5 == pcVar4) {
      pcVar5 = in_EAX;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = pcVar5;
    }
    uVar2 = extraout_ECX;
    if (((param_1 == 1) && ((undefined *)0x7fffffff < puVar6)) &&
       ((puVar6 != (undefined *)0x80000000 || ((extraout_ECX >> 8 & 0xff) != 0x2d)))) {
      uVar2 = CONCAT31(uVar3,1);
    }
    if ((char)uVar2 == '\0') {
      if ((uVar2 >> 8 & 0xff) == 0x2d) {
        puVar6 = (undefined *)-(int)puVar6;
      }
    }
    else {
      FUN_00403848(uVar2,pcVar5);
      if (param_1 == 0) {
        puVar6 = (undefined *)0xffffffff;
      }
      else if (extraout_CH == '-') {
        puVar6 = (undefined *)0x80000000;
      }
      else {
        puVar6 = (undefined *)0x7fffffff;
      }
    }
  }
  return puVar6;
}


