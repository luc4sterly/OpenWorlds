// 10039530 RwGetDisplayDevices [Global]
// program: RWL21.DLL

char * RwGetDisplayDevices(void)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
                    /* 0x39530  180  RwGetDisplayDevices */
  if (DAT_1005b754 == 0) {
    FUN_1000cba0(0x55);
    pcVar2 = (char *)0x0;
  }
  else {
    if (DAT_1005b74c == (char *)0x0) {
      pcVar2 = FUN_10043fd0();
      if (pcVar2 == (char *)0x0) {
        DAT_1005b74c = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(1);
        if (DAT_1005b74c != (char *)0x0) {
          *DAT_1005b74c = DAT_1005b784;
        }
      }
      else {
        uVar3 = 0xffffffff;
        pcVar5 = pcVar2;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        DAT_1005b74c = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar3);
        if (DAT_1005b74c != (char *)0x0) {
          uVar3 = 0xffffffff;
          pcVar5 = pcVar2;
          do {
            pcVar6 = pcVar5;
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            pcVar6 = pcVar5 + 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar6;
          } while (cVar1 != '\0');
          uVar3 = ~uVar3;
          pcVar5 = pcVar6 + -uVar3;
          pcVar6 = DAT_1005b74c;
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
            pcVar5 = pcVar5 + 4;
            pcVar6 = pcVar6 + 4;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar6 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          }
        }
        (**(code **)(PTR_DAT_1005b69c + 0x358))(pcVar2);
      }
    }
    pcVar2 = DAT_1005b74c;
    if (DAT_1005b74c == (char *)0x0) {
      FUN_1000cba0(0x54);
      pcVar2 = DAT_1005b74c;
    }
  }
  return pcVar2;
}


