// 00405466 FUN_00405466 [Global]
// program: gdkup.exe

void FUN_00405466(void)

{
  byte in_AL;
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_0040a296;
    bVar1 = in_AL;
    for (pcVar3 = &DAT_0040a278; pcVar3 < &DAT_0040a296; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && ((byte)pcVar3[1] <= bVar1)) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_0040a296) break;
    if (*(code **)(pcVar2 + 2) != (code *)0x0) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


