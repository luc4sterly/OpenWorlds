// 004010a5 FUN_004010a5 [Global]
// programa: gdkup.exe

void FUN_004010a5(void)

{
  BOOL BVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined8 uVar3;
  undefined8 uVar4;
  tagMSG local_6c;
  CLSID local_50;
  LPUNKNOWN local_40;
  int local_3c;
  int local_38;
  LPCOLESTR local_34;
  int local_30;
  DWORD local_2c;
  LPUNKNOWN local_28;
  DWORD local_24;
  IUnknown *local_20;
  LPUNKNOWN local_1c;
  
  CoInitialize((LPVOID)0x0);
  uVar3 = FUN_004026f4(extraout_ECX,extraout_EDX);
  local_3c = (int)uVar3;
  local_38 = local_3c;
  if (local_3c == 0) {
    local_1c = (LPUNKNOWN)0x0;
    uVar2 = extraout_ECX_00;
  }
  else {
    uVar4 = FUN_0040129c(extraout_ECX_00,(int)((ulonglong)uVar3 >> 0x20));
    uVar3 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),local_3c);
    local_40 = (LPUNKNOWN)uVar4;
    uVar2 = extraout_ECX_01;
    local_1c = local_40;
  }
  local_3c = (int)uVar3;
  local_28 = local_1c;
  if (local_1c != (LPUNKNOWN)0x0) {
    uVar3 = FUN_00401010(uVar2,(int)((ulonglong)uVar3 >> 0x20));
    local_34 = (LPCOLESTR)uVar3;
    if (local_34 != (LPCOLESTR)0x0) {
      local_30 = CLSIDFromString(local_34,&local_50);
      Ordinal_6(local_34);
      if (local_30 == 0) {
        local_30 = CoRegisterClassObject(&local_50,local_28,4,1,&local_2c);
        if (local_30 == 0) {
          DAT_0040b010 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
          do {
            BVar1 = GetMessageA(&local_6c,(HWND)0x0,0,0);
            if (BVar1 != 0) {
              DispatchMessageA(&local_6c);
            }
            local_24 = WaitForSingleObject(DAT_0040b010,0);
          } while (local_24 != 0);
          CoRevokeClassObject(local_2c);
          local_20 = local_28;
          (*local_28->lpVtbl->Release)(local_28);
          CoUninitialize();
        }
      }
    }
  }
  return;
}


