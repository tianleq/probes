package probe;

import org.dacapo.harness.Callback;
import org.dacapo.harness.CommandLineArgs;

public class DacapoChopinCallback extends Callback {
  public DacapoChopinCallback(CommandLineArgs cla) {
    super(cla);
    ProbeMux.init();
  }

  public void start(String benchmark) {
    ProbeMux.begin(benchmark, isWarmup());
    super.start(benchmark);
  };

  /* Immediately after the end of the benchmark */
  public void stop(long duration) {
    super.stop(duration);
    ProbeMux.end(isWarmup());
    if (!isWarmup()) {
      ProbeMux.cleanup();
    }
  }
  
  /**
   * The workload is about to start issuing requests.
   *
   * Some workloads do substantial work prior (e.g. building a
   * database) prior to issuing requests.  This call brackets
   * the begining of the request-based behavior.
   */
  public void requestsStarting() {
    if (!isWarmup()) {
      requests_starting_native();
    }
  }

  /**
   * The workload has finished issuing requests.
   */
  public void requestsFinished() {

    if (!isWarmup()) {
      requests_finished_native();
    }
  }

  public void requestEnd(int id) {
    request_finish_native();
  }

  /* Called by server-side code at completion of servicing a request (request-based workloads only) */
  @Override
  public void serverTaskEnd() { 
    /* your code here */ 
     request_finish_native();
  }

  public native void request_finish_native();

  public native void requests_starting_native();
  public native void requests_finished_native();
}
