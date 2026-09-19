// 10066e70 ___init_numeric [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *unaff_EDI;
  uint _Lc_type;
  
  _Lc_type = (uint)DAT_1007ae1a;
  if (DAT_1007a718 != 0) {
    iVar1 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,0x1007ade4,unaff_EDI);
    iVar2 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,0x1007ade8,unaff_EDI);
    iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,0x1007adec,unaff_EDI);
    fix_grouping(DAT_1007adec);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      _free(DAT_1007ade4);
      _free(DAT_1007ade8);
      _free(DAT_1007adec);
      DAT_1007ade4 = (void *)0x0;
      DAT_1007ade8 = (void *)0x0;
      DAT_1007adec = (char *)0x0;
      return -1;
    }
    if (*(undefined **)PTR_PTR_1007b710 != &DAT_1007b6d8) {
      _free(*(undefined **)PTR_PTR_1007b710);
      _free(*(void **)(PTR_PTR_1007b710 + 4));
      _free(*(void **)(PTR_PTR_1007b710 + 8));
    }
    *(void **)PTR_PTR_1007b710 = DAT_1007ade4;
    *(void **)(PTR_PTR_1007b710 + 4) = DAT_1007ade8;
    *(char **)(PTR_PTR_1007b710 + 8) = DAT_1007adec;
    _DAT_100799c4 = 1;
    DAT_100799c0 = **(undefined1 **)PTR_PTR_1007b710;
    return 0;
  }
  _free(DAT_1007ade4);
  _free(DAT_1007ade8);
  _free(DAT_1007adec);
  DAT_1007ade4 = (void *)0x0;
  DAT_1007ade8 = (void *)0x0;
  DAT_1007adec = (char *)0x0;
  pvVar4 = _malloc(2);
  *(void **)PTR_PTR_1007b710 = pvVar4;
  if (*(undefined2 **)PTR_PTR_1007b710 == (undefined2 *)0x0) {
    return -1;
  }
  **(undefined2 **)PTR_PTR_1007b710 = DAT_1007854c;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_1007b710 + 4) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_1007b710 + 4) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_1007b710 + 4) = 0;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_1007b710 + 8) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_1007b710 + 8) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_1007b710 + 8) = 0;
  _DAT_100799c4 = 1;
  DAT_100799c0 = **(undefined1 **)PTR_PTR_1007b710;
  return 0;
}


