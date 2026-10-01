// 0042cd01 FUN_0042cd01 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042cd01(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  uint uVar3;
  uint extraout_ECX;
  char *pcVar4;
  undefined8 uVar5;
  
  uVar3 = 0xffffffff;
  pcVar2 = in_EAX;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar5 = FUN_0042ba46(~uVar3,param_2);
  pcVar2 = (char *)uVar5;
  if (pcVar2 != (char *)0x0) {
    pcVar4 = pcVar2;
    for (uVar3 = extraout_ECX >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)in_EAX;
      in_EAX = in_EAX + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar3 = extraout_ECX & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *in_EAX;
      in_EAX = in_EAX + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  return CONCAT44(param_2,pcVar2);
}


