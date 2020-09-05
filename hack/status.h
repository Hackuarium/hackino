
#ifdef PARAM_ERROR

boolean isError(int filter) {
  if ((getParameter(PARAM_ERROR) & filter) != 0)
    return true;
  return false;
}

boolean isError() {
  return (getParameter(PARAM_ERROR) != 0);
}

#endif

#ifdef PARAM_ENABLED
boolean isEnabled(byte statusFlag) {
  return getParameterBit(PARAM_ENABLED, statusFlag);
}
#endif

#if defined(PARAM_STATUS) && defined(EVENT_STATUS_ENABLE) && \
    defined(EVENT_STATUS_DISABLE)

boolean getStatus(byte statusFlag) {
  return getParameterBit(PARAM_STATUS, statusFlag);
}

boolean isRunning(byte statusFlag) {
  return getParameterBit(PARAM_STATUS, statusFlag);
}

boolean startProcess(byte statusFlag) {
  boolean statusChanged = setParameterBit(PARAM_STATUS, statusFlag);
#ifdef EVENT_LOGGING
  if (statusChanged) {
    writeLog(EVENT_STATUS_ENABLE, statusFlag);
  }
#endif
  return statusChanged;
}

boolean stopProcess(byte statusFlag) {
  boolean statusChanged = clearParameterBit(PARAM_STATUS, statusFlag);
#ifdef EVENT_LOGGING
  if (statusChanged) {
    writeLog(EVENT_STATUS_DISABLE, statusFlag);
  }
#endif
  return statusChanged;
}

#endif