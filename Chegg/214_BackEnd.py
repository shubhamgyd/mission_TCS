# Dictionary
peer_mentor = {"name": "Andrew",
               "courses": ["COP 3502C", "COP 3520"],
               "run_discussion": True,
               "hold_office_hours": True,
               "working_hours": 8
               }

try:
    # Remove first course from courses
    peer_mentor["courses"][0:1] = []
    # delete key run_discussion
    del peer_mentor["run_discussion"]
    # Print courses
    print(peer_mentor["courses"])
    # pop method return the items of that field
    print(peer_mentor.pop("run_discussion", "no discussion"))
# If any error occurs
except:
    print("Someting is wrong")
