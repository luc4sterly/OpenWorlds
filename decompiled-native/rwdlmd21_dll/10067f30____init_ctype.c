// 10067f30 ___init_ctype [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    ___init_ctype
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_ctype(threadlocinfo *_LocInfo)

{
  byte bVar1;
  int iVar2;
  undefined2 *_Memory;
  undefined2 *_Memory_00;
  BOOL BVar3;
  uint uVar4;
  undefined1 *puVar5;
  LPCWSTR pWVar6;
  undefined2 *puVar7;
  BYTE *pBVar8;
  void *unaff_EBP;
  undefined1 *_Memory_01;
  LPCWSTR local_18;
  _cpinfo local_14;
  
  _Memory_01 = (undefined1 *)0x0;
  local_18 = (LPCWSTR)0x0;
  if (DAT_10088740 == 0) {
    PTR_DAT_100879f8 = &DAT_10087a02;
    PTR_DAT_100879fc = &DAT_10087a02;
    _free(DAT_10088e24);
    _free(DAT_10088e28);
    DAT_10088e24 = (undefined2 *)0x0;
    DAT_10088e28 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_10088750 != 0) ||
     (iVar2 = ___getlocaleinfo((_locale_t)0x0,(uint)DAT_10088e3c,(LPCWSTR)0xb,0x10088750,unaff_EBP),
     _Memory_00 = (undefined2 *)local_14.MaxCharSize, _Memory = (undefined2 *)local_14.MaxCharSize,
     iVar2 == 0)) {
    _Memory = _malloc(0x202);
    _Memory_00 = _malloc(0x202);
    _Memory_01 = _malloc(0x101);
    local_18 = _malloc(0x202);
    if ((_Memory != (undefined2 *)0x0) &&
       (((_Memory_00 != (undefined2 *)0x0 && (_Memory_01 != (undefined1 *)0x0)) &&
        (local_18 != (LPCWSTR)0x0)))) {
      iVar2 = 0;
      puVar5 = _Memory_01;
      do {
        *puVar5 = (char)iVar2;
        puVar5 = puVar5 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x100);
      BVar3 = GetCPInfo(DAT_10088750,&local_14);
      if ((BVar3 != 0) && (local_14.MaxCharSize < (undefined2 *)0x3)) {
        DAT_100879ec = local_14.MaxCharSize & 0xffff;
        if (1 < DAT_100879ec) {
          pBVar8 = local_14.LeadByte;
          bVar1 = local_14.LeadByte[0];
          while ((bVar1 != 0 && (pBVar8[1] != 0))) {
            uVar4 = (uint)*pBVar8;
            if (uVar4 <= pBVar8[1]) {
              do {
                _Memory_01[uVar4] = 0;
                uVar4 = uVar4 + 1;
              } while ((int)uVar4 <= (int)(uint)pBVar8[1]);
            }
            pBVar8 = pBVar8 + 2;
            bVar1 = *pBVar8;
          }
        }
        BVar3 = ___crtGetStringTypeA
                          ((_locale_t)0x1,(DWORD)_Memory_01,(LPCSTR)0x100,(int)(_Memory + 1),
                           (LPWORD)0x0,0,(BOOL)unaff_EBP);
        if (BVar3 != 0) {
          *_Memory = 0;
          iVar2 = 0;
          pWVar6 = local_18;
          do {
            *pWVar6 = (WCHAR)iVar2;
            pWVar6 = pWVar6 + 1;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x100);
          BVar3 = ___crtGetStringTypeW(1,local_18,0x100,_Memory_00 + 1,0,0);
          if (BVar3 != 0) {
            *_Memory_00 = 0;
            if (1 < (int)DAT_100879ec) {
              pBVar8 = local_14.LeadByte;
              while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
                uVar4 = (uint)*pBVar8;
                if (uVar4 <= pBVar8[1]) {
                  puVar7 = _Memory + uVar4 + 1;
                  do {
                    *puVar7 = 0x8000;
                    puVar7 = puVar7 + 1;
                    uVar4 = uVar4 + 1;
                  } while ((int)uVar4 <= (int)(uint)pBVar8[1]);
                }
                pBVar8 = pBVar8 + 2;
                local_14.LeadByte[0] = *pBVar8;
              }
            }
            PTR_DAT_100879f8 = (undefined *)(_Memory + 1);
            PTR_DAT_100879fc = (undefined *)(_Memory_00 + 1);
            if (DAT_10088e24 != (void *)0x0) {
              _free(DAT_10088e24);
            }
            DAT_10088e24 = _Memory;
            if (DAT_10088e28 != (void *)0x0) {
              _free(DAT_10088e28);
            }
            DAT_10088e28 = _Memory_00;
            _free(_Memory_01);
            _free(local_18);
            return 0;
          }
        }
      }
    }
  }
  _free(_Memory);
  _free(_Memory_00);
  _free(_Memory_01);
  _free(local_18);
  return 1;
}


