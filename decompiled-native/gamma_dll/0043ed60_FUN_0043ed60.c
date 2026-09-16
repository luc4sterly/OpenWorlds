// 0043ed60 FUN_0043ed60 [Global]
// programa: gamma.dll

undefined4 FUN_0043ed60(int param_1,char *param_2,int *param_3)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  piVar1 = (int *)(param_1 + -0x14);
  if (param_3 == (int *)0x0) {
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
    cVar3 = *pcVar7;
    cVar2 = *pcVar5;
    pcVar5 = pcVar6;
    pcVar7 = pcVar8;
  } while (cVar2 == cVar3);
  if (pcVar6[-1] == pcVar8[-1]) {
    *param_3 = (int)piVar1;
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
      cVar3 = *pcVar7;
      cVar2 = *pcVar5;
      pcVar5 = pcVar6;
      pcVar7 = pcVar8;
    } while (cVar2 == cVar3);
    if (pcVar6[-1] == pcVar8[-1]) {
      iVar4 = 0;
      if (piVar1 != (int *)0x0) {
        iVar4 = param_1 + -0x10;
      }
      *param_3 = iVar4;
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
        cVar3 = *pcVar7;
        cVar2 = *pcVar5;
        pcVar5 = pcVar6;
        pcVar7 = pcVar8;
      } while (cVar2 == cVar3);
      if (pcVar6[-1] == pcVar8[-1]) {
        iVar4 = 0;
        if (piVar1 != (int *)0x0) {
          iVar4 = param_1 + -0xc;
        }
        *param_3 = iVar4;
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
          cVar3 = *pcVar7;
          cVar2 = *pcVar5;
          pcVar5 = pcVar6;
          pcVar7 = pcVar8;
        } while (cVar2 == cVar3);
        if (pcVar6[-1] == pcVar8[-1]) {
          iVar4 = 0;
          if (piVar1 != (int *)0x0) {
            iVar4 = param_1 + -0xc;
          }
          *param_3 = iVar4;
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
            cVar3 = *pcVar7;
            cVar2 = *pcVar5;
            pcVar5 = pcVar6;
            pcVar7 = pcVar8;
          } while (cVar2 == cVar3);
          if (pcVar6[-1] == pcVar8[-1]) {
            iVar4 = 0;
            if (piVar1 != (int *)0x0) {
              iVar4 = param_1 + -8;
            }
            *param_3 = iVar4;
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
              cVar3 = *pcVar7;
              cVar2 = *pcVar5;
              pcVar5 = pcVar6;
              pcVar7 = pcVar8;
            } while (cVar2 == cVar3);
            if (pcVar6[-1] == pcVar8[-1]) {
              *param_3 = (int)piVar1;
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
                cVar3 = *pcVar7;
                cVar2 = *pcVar5;
                pcVar5 = pcVar6;
                pcVar7 = pcVar8;
              } while (cVar2 == cVar3);
              if (pcVar6[-1] == pcVar8[-1]) {
                iVar4 = 0;
                if (piVar1 != (int *)0x0) {
                  iVar4 = param_1 + -4;
                }
                *param_3 = iVar4;
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
                  cVar3 = *pcVar7;
                  cVar2 = *pcVar5;
                  pcVar5 = pcVar6;
                  pcVar7 = pcVar8;
                } while (cVar2 == cVar3);
                if (pcVar6[-1] == pcVar8[-1]) {
                  *param_3 = (int)piVar1;
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
                    cVar3 = *pcVar7;
                    cVar2 = *pcVar5;
                    pcVar5 = pcVar6;
                    pcVar7 = pcVar8;
                  } while (cVar2 == cVar3);
                  if (pcVar6[-1] == pcVar8[-1]) {
                    iVar4 = 0;
                    if (piVar1 != (int *)0x0) {
                      iVar4 = param_1;
                    }
                    *param_3 = iVar4;
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
                      cVar3 = *pcVar5;
                      cVar2 = *param_2;
                      param_2 = pcVar7;
                      pcVar5 = pcVar6;
                    } while (cVar2 == cVar3);
                    if (pcVar7[-1] != pcVar6[-1]) {
                      *param_3 = 0;
                      return 0x80004002;
                    }
                    *param_3 = (int)piVar1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  (**(code **)(*piVar1 + 4))(piVar1);
  return 0;
}


