// 00431d41 FUN_00431d41 [Global]
// program: sfmain.exe

void __fastcall FUN_00431d41(undefined4 param_1,byte param_2)

{
  byte in_AL;
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_0043eb2e;
    bVar1 = in_AL;
    for (pcVar3 = &DAT_0043eb1c; pcVar3 < &DAT_0043eb2e; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && (bVar1 <= (byte)pcVar3[1])) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_0043eb2e) break;
    if ((bVar1 <= param_2) && (*(code **)(pcVar2 + 2) != (code *)0x0)) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


