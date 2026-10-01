// 00402c7c FUN_00402c7c [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00402c7c(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  bool bVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_0040387b();
  uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
  uVar2 = (uint)uVar6 & 0xff;
  if (((uVar2 != 0x72) && (uVar2 != 0x77)) && (uVar2 != 0x61)) {
    FUN_00403848(extraout_ECX,uVar3);
    uVar3 = 0;
    goto LAB_00402d45;
  }
  cVar1 = *(char *)(in_EAX + 1);
  uVar2 = uVar3 | 3;
  if (cVar1 == '+') {
    uVar4 = CONCAT22((short)((ulonglong)uVar6 >> 0x30),(short)uVar2) | 0x40;
    if (*(char *)(in_EAX + 2) == 'b') {
LAB_00402ce9:
      uVar3 = uVar4;
    }
    else {
      uVar3 = uVar2;
      if (*(char *)(in_EAX + 2) != 't') {
        bVar5 = DAT_00408dcd == 0x200;
LAB_00402ce7:
        if (bVar5) goto LAB_00402ce9;
      }
    }
  }
  else {
    uVar4 = uVar3 | 0x40;
    if (cVar1 == 'b') {
      uVar3 = uVar4;
      if (*(char *)(in_EAX + 2) == '+') {
        uVar4 = CONCAT31((int3)((ulonglong)uVar6 >> 0x28),(char)uVar4) | 3;
LAB_00402d25:
        uVar3 = uVar4;
      }
    }
    else {
      if (cVar1 == 't') {
        bVar5 = *(char *)(in_EAX + 2) == '+';
        uVar4 = uVar2;
        goto LAB_00402ce7;
      }
      if (DAT_00408dcd == 0x200) goto LAB_00402d25;
    }
  }
  uVar2 = (uint)uVar6 & 0xff;
  if (uVar2 == 0x77) {
    uVar3 = uVar3 | 2;
  }
  else if (uVar2 == 0x61) {
    uVar3 = uVar3 | 0x82;
  }
  else {
    uVar3 = uVar3 | 1;
  }
LAB_00402d45:
  return CONCAT44(param_2,uVar3);
}


