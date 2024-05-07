import subprocess

def run_detection_script():
    command = ['python', 'detect.py', '--weights', 'yolov5s.pt', '--source', '0']

    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)

    while True:
        # Read stdout and stderr simultaneously
        stdout_line = process.stdout.readline()
        stderr_line = process.stderr.readline()
        
        # Check if the process has finished
        if (stdout_line == '' and stderr_line == '') and process.poll() is not None:
            break
        
        # Print stdout and stderr lines
        if stdout_line:
            print("STDOUT:", stdout_line.strip())
            process_output(stdout_line.strip())
        if stderr_line:
            print("STDERR:", stderr_line.strip())

    remaining_output, remaining_error = process.communicate()
    if remaining_output:
        print("Remaining output:", remaining_output.strip())
    if remaining_error:
        print("Error:", remaining_error.strip())

def process_output(output):
    # Define conditions to trigger specific actions based on the output
    if "persons" in output:
        execute_action_for_person_detected()
    elif "car" in output:
        execute_action_for_car_detected()
    # Add more conditions as needed

def execute_action_for_person_detected():
    # Execute specific action for person detection
    print("Person detected! Taking action...")

def execute_action_for_car_detected():
    # Execute specific action for car detection
    print("Car detected! Taking action...")

if __name__ == "__main__":
    run_detection_script()
