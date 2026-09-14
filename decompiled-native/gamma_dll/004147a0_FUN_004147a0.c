// 004147a0 FUN_004147a0 [Global]
// programa: gamma.dll

int __cdecl FUN_004147a0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00419390(param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_00419540(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_00419390(iVar1);
    if (iVar2 == 0) {
      iVar1 = FUN_00419540(iVar1);
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_00419390(iVar1);
        if (iVar2 == 0) {
          iVar1 = FUN_00419540(iVar1);
          if (iVar1 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_00419390(iVar1);
            if (iVar2 == 0) {
              iVar1 = FUN_00419540(iVar1);
              if (iVar1 == 0) {
                iVar2 = 0;
              }
              else {
                iVar2 = FUN_00419390(iVar1);
                if (iVar2 == 0) {
                  iVar1 = FUN_00419540(iVar1);
                  if (iVar1 == 0) {
                    iVar2 = 0;
                  }
                  else {
                    iVar2 = FUN_00419390(iVar1);
                    if (iVar2 == 0) {
                      iVar1 = FUN_00419540(iVar1);
                      if (iVar1 == 0) {
                        iVar2 = 0;
                      }
                      else {
                        iVar2 = FUN_00419390(iVar1);
                        if (iVar2 == 0) {
                          iVar1 = FUN_00419540(iVar1);
                          if (iVar1 == 0) {
                            iVar2 = 0;
                          }
                          else {
                            iVar2 = FUN_00419390(iVar1);
                            if (iVar2 == 0) {
                              iVar1 = FUN_00419540(iVar1);
                              if (iVar1 == 0) {
                                iVar2 = 0;
                              }
                              else {
                                iVar2 = FUN_00419390(iVar1);
                                if (iVar2 == 0) {
                                  iVar1 = FUN_00419540(iVar1);
                                  if (iVar1 == 0) {
                                    iVar2 = 0;
                                  }
                                  else {
                                    iVar2 = FUN_004147a0(iVar1);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return iVar2;
  }
  return 0;
}


