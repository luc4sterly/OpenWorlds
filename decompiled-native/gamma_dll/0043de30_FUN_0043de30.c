// 0043de30 FUN_0043de30 [Global]
// program: gamma.dll

undefined4 FUN_0043de30(int *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar4 = 0x10;
  pcVar5 = param_2;
  pcVar7 = "\x18\x01";
  do {
    pcVar6 = pcVar5;
    pcVar8 = pcVar7;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar7 + 1;
    pcVar6 = pcVar5 + 1;
    cVar2 = *pcVar7;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
    pcVar7 = pcVar8;
  } while (cVar1 == cVar2);
  if (pcVar6[-1] == pcVar8[-1]) {
    *param_3 = param_1;
  }
  else {
    iVar4 = 0x10;
    pcVar5 = param_2;
    pcVar7 = "\x19\x01";
    do {
      pcVar6 = pcVar5;
      pcVar8 = pcVar7;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar7 + 1;
      pcVar6 = pcVar5 + 1;
      cVar2 = *pcVar7;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
      pcVar7 = pcVar8;
    } while (cVar1 == cVar2);
    if (pcVar6[-1] == pcVar8[-1]) {
      piVar3 = param_1;
      if (param_1 != (int *)0x0) {
        piVar3 = param_1 + 1;
      }
      *param_3 = piVar3;
    }
    else {
      iVar4 = 0x10;
      pcVar5 = param_2;
      pcVar7 = "\x16\x01";
      do {
        pcVar6 = pcVar5;
        pcVar8 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = pcVar7 + 1;
        pcVar6 = pcVar5 + 1;
        cVar2 = *pcVar7;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
        pcVar7 = pcVar8;
      } while (cVar1 == cVar2);
      if (pcVar6[-1] == pcVar8[-1]) {
        piVar3 = param_1;
        if (param_1 != (int *)0x0) {
          piVar3 = param_1 + 2;
        }
        *param_3 = piVar3;
      }
      else {
        iVar4 = 0x10;
        pcVar5 = param_2;
        pcVar7 = "\x15\x01";
        do {
          pcVar6 = pcVar5;
          pcVar8 = pcVar7;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar8 = pcVar7 + 1;
          pcVar6 = pcVar5 + 1;
          cVar2 = *pcVar7;
          cVar1 = *pcVar5;
          pcVar5 = pcVar6;
          pcVar7 = pcVar8;
        } while (cVar1 == cVar2);
        if (pcVar6[-1] == pcVar8[-1]) {
          piVar3 = param_1;
          if (param_1 != (int *)0x0) {
            piVar3 = param_1 + 2;
          }
          *param_3 = piVar3;
        }
        else {
          iVar4 = 0x10;
          pcVar5 = param_2;
          pcVar7 = &DAT_00467018;
          do {
            pcVar6 = pcVar5;
            pcVar8 = pcVar7;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar8 = pcVar7 + 1;
            pcVar6 = pcVar5 + 1;
            cVar2 = *pcVar7;
            cVar1 = *pcVar5;
            pcVar5 = pcVar6;
            pcVar7 = pcVar8;
          } while (cVar1 == cVar2);
          if (pcVar6[-1] == pcVar8[-1]) {
            piVar3 = param_1;
            if (param_1 != (int *)0x0) {
              piVar3 = param_1 + 3;
            }
            *param_3 = piVar3;
          }
          else {
            iVar4 = 0x10;
            pcVar5 = param_2;
            pcVar7 = "\x14\x01";
            do {
              pcVar6 = pcVar5;
              pcVar8 = pcVar7;
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              pcVar8 = pcVar7 + 1;
              pcVar6 = pcVar5 + 1;
              cVar2 = *pcVar7;
              cVar1 = *pcVar5;
              pcVar5 = pcVar6;
              pcVar7 = pcVar8;
            } while (cVar1 == cVar2);
            if (pcVar6[-1] == pcVar8[-1]) {
              *param_3 = param_1;
            }
            else {
              iVar4 = 0x10;
              pcVar5 = param_2;
              pcVar7 = &DAT_00467048;
              do {
                pcVar6 = pcVar5;
                pcVar8 = pcVar7;
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                pcVar8 = pcVar7 + 1;
                pcVar6 = pcVar5 + 1;
                cVar2 = *pcVar7;
                cVar1 = *pcVar5;
                pcVar5 = pcVar6;
                pcVar7 = pcVar8;
              } while (cVar1 == cVar2);
              if (pcVar6[-1] == pcVar8[-1]) {
                piVar3 = param_1;
                if (param_1 != (int *)0x0) {
                  piVar3 = param_1 + 4;
                }
                *param_3 = piVar3;
              }
              else {
                iVar4 = 0x10;
                pcVar5 = param_2;
                pcVar7 = &DAT_00467038;
                do {
                  pcVar6 = pcVar5;
                  pcVar8 = pcVar7;
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  pcVar8 = pcVar7 + 1;
                  pcVar6 = pcVar5 + 1;
                  cVar2 = *pcVar7;
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar6;
                  pcVar7 = pcVar8;
                } while (cVar1 == cVar2);
                if (pcVar6[-1] == pcVar8[-1]) {
                  *param_3 = param_1;
                }
                else {
                  iVar4 = 0x10;
                  pcVar5 = param_2;
                  pcVar7 = "";
                  do {
                    pcVar6 = pcVar5;
                    pcVar8 = pcVar7;
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    pcVar8 = pcVar7 + 1;
                    pcVar6 = pcVar5 + 1;
                    cVar2 = *pcVar7;
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar6;
                    pcVar7 = pcVar8;
                  } while (cVar1 == cVar2);
                  if (pcVar6[-1] == pcVar8[-1]) {
                    piVar3 = param_1;
                    if (param_1 != (int *)0x0) {
                      piVar3 = param_1 + 5;
                    }
                    *param_3 = piVar3;
                  }
                  else {
                    iVar4 = 0x10;
                    pcVar5 = "";
                    do {
                      pcVar7 = param_2;
                      pcVar6 = pcVar5;
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      pcVar6 = pcVar5 + 1;
                      pcVar7 = param_2 + 1;
                      cVar2 = *pcVar5;
                      cVar1 = *param_2;
                      param_2 = pcVar7;
                      pcVar5 = pcVar6;
                    } while (cVar1 == cVar2);
                    if (pcVar7[-1] != pcVar6[-1]) {
                      *param_3 = 0;
                      return 0x80004002;
                    }
                    *param_3 = param_1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


