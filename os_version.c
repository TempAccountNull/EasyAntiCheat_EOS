__int64 EOS::GetOperatingSystemVersion()
{
  __int64 result;
  struct _OSVERSIONINFOW VersionInformation; 

  result = (unsigned int)EOS::Globals::OperatingSystemVersion;
  if ( !EOS::Globals::OperatingSystemVersion )
  {
    EOS::wrappers::memset(&VersionInformation.dwMajorVersion, 0i64, 0x118);
    VersionInformation.dwOSVersionInfoSize = 0x11C;
    RtlGetVersion(&VersionInformation);
    result = VersionInformation.dwBuildNumber;
    EOS::Globals::OperatingSystemVersion = VersionInformation.dwBuildNumber;
  }
  return result;
}
